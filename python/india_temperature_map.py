
import json
import requests
import plotly.graph_objects as go

# ── Temperature data: avg high & low (°C) per state, 2020-2024 ──
state_data = {
    "Andhra Pradesh":     {"high": 34.2, "low": 23.1},
    "Arunachal Pradesh":  {"high": 22.4, "low": 10.2},
    "Assam":              {"high": 28.1, "low": 16.8},
    "Bihar":              {"high": 33.6, "low": 18.4},
    "Chhattisgarh":       {"high": 33.1, "low": 19.6},
    "Goa":                {"high": 33.0, "low": 24.2},
    "Gujarat":            {"high": 36.4, "low": 22.5},
    "Haryana":            {"high": 35.2, "low": 14.6},
    "Himachal Pradesh":   {"high": 20.1, "low":  7.4},
    "Jharkhand":          {"high": 32.8, "low": 18.1},
    "Karnataka":          {"high": 30.6, "low": 19.8},
    "Kerala":             {"high": 31.4, "low": 23.6},
    "Madhya Pradesh":     {"high": 34.8, "low": 18.9},
    "Maharashtra":        {"high": 33.5, "low": 20.4},
    "Manipur":            {"high": 25.6, "low": 12.4},
    "Meghalaya":          {"high": 22.8, "low": 12.1},
    "Mizoram":            {"high": 24.3, "low": 13.5},
    "Nagaland":           {"high": 23.9, "low": 11.8},
    "Odisha":             {"high": 34.5, "low": 21.3},
    "Punjab":             {"high": 34.9, "low": 14.2},
    "Rajasthan":          {"high": 38.7, "low": 16.8},
    "Sikkim":             {"high": 18.2, "low":  6.8},
    "Tamil Nadu":         {"high": 34.1, "low": 24.2},
    "Telangana":          {"high": 35.3, "low": 22.8},
    "Tripura":            {"high": 29.4, "low": 17.6},
    "Uttar Pradesh":      {"high": 34.3, "low": 16.2},
    "Uttarakhand":        {"high": 24.6, "low": 10.1},
    "West Bengal":        {"high": 32.4, "low": 19.8},
    "Andaman and Nicobar Islands": {"high": 31.8, "low": 25.1},
    "Chandigarh":         {"high": 34.6, "low": 15.2},
    "Dadra and Nagar Haveli and Daman and Diu": {"high": 34.8, "low": 22.4},
    "Delhi":              {"high": 36.1, "low": 15.8},
    "Jammu and Kashmir":  {"high": 23.4, "low":  4.2},
    "Ladakh":             {"high": 14.6, "low": -2.8},
    "Lakshadweep":        {"high": 31.6, "low": 26.2},
    "Puducherry":         {"high": 33.8, "low": 24.6},
}

# ── Load GeoJSON boundary data for Indian states ──
GEOJSON_URL = (
    "https://cdn.jsdelivr.net/npm/india-states-geojson@1.0.0/india-states.geojson"
)

print("Fetching India GeoJSON boundary data...")
response = requests.get(GEOJSON_URL, timeout=15)
response.raise_for_status()
india_geojson = response.json()
print(f"Loaded {len(india_geojson['features'])} state/UT features.")

# ── Attach temperature values to each GeoJSON feature ──
# We'll use "id" on each feature so Plotly's choropleth can match them.
for feature in india_geojson["features"]:
    props = feature["properties"]
    name = props.get("NAME_1") or props.get("name") or props.get("state", "")
    d = state_data.get(name, {})
    props["state_name"] = name
    props["avg_high"]   = d.get("high", None)
    props["avg_low"]    = d.get("low",  None)
    props["temp_range"] = (
        round(d["high"] - d["low"], 1) if d else None
    )
    feature["id"] = name  # Plotly uses feature["id"] for matching

# ── Build lists for the choropleth ──
locations, z_high, z_low, z_range, hover_texts = [], [], [], [], []

for feature in india_geojson["features"]:
    props   = feature["properties"]
    name    = props["state_name"]
    high    = props["avg_high"]
    low     = props["avg_low"]
    t_range = props["temp_range"]

    if high is None:
        continue

    locations.append(name)
    z_high.append(high)
    z_low.append(low)
    z_range.append(t_range)

    hover_texts.append(
        f"<b>{name}</b><br>"
        f"Avg High: {high}°C<br>"
        f"Avg Low : {low}°C<br>"
        f"Range   : {t_range}°C"
    )

# ── Build the Plotly figure ──
fig = go.Figure(
    go.Choropleth(
        geojson=india_geojson,
        locations=locations,
        featureidkey="id",
        z=z_high,
        text=hover_texts,
        hoverinfo="text",
        colorscale=[
            [0.00, "#2166ac"],   # cool blue  – below 14°C
            [0.25, "#74add1"],   # light blue – ~28°C
            [0.50, "#fee090"],   # amber      – ~31°C
            [0.75, "#f46d43"],   # orange     – ~34°C
            [1.00, "#d73027"],   # deep red   – above 38°C
        ],
        zmin=10,
        zmax=40,
        colorbar=dict(
            title=dict(text="Avg High (°C)", side="right"),
            thickness=14,
            len=0.6,
            tickvals=[10, 20, 28, 31, 34, 37, 40],
            ticktext=["10", "20", "28", "31", "34", "37", "40"],
        ),
        marker_line_color="white",
        marker_line_width=0.6,
    )
)

fig.update_geos(
    visible=False,
    fitbounds="locations",   # auto-zoom to India
    resolution=50,
)

fig.update_layout(
    title=dict(
        text="India — Average Temperature by State (2020–2024)",
        x=0.5,
        xanchor="center",
        font=dict(size=18),
    ),
    geo=dict(
        showframe=False,
        showcoastlines=False,
        bgcolor="rgba(0,0,0,0)",
    ),
    margin=dict(l=0, r=0, t=60, b=0),
    height=700,
    paper_bgcolor="white",
    plot_bgcolor="white",
    hoverlabel=dict(
        bgcolor="white",
        bordercolor="#ccc",
        font_size=13,
    ),
)

print("Rendering interactive map...")
fig.show()

# ── Optional: save as standalone HTML ──
# fig.write_html("india_temperature_map.html")
# print("Saved to india_temperature_map.html")

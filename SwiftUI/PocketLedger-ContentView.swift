import SwiftUI

struct Expense: Identifiable {
    let id = UUID()
    var name: String
    var amount: Double
    var category: String
}
struct ContentView: View {
    @State private var expenses = [
        Expense(name: "Coffee", amount: 100, category: "Food"),
        Expense(name: "Fuel", amount: 200, category: "Transport"),
        Expense(name: "Food", amount: 150, category: "Food"),
        Expense(name: "Movie", amount: 420, category: "Entertainment")
    ]
    var totalSpent: Double {
        expenses.reduce(0) { total, expense in
            total + expense.amount
        }
    }
    //the below is a simpler code for the above section.
    /*var totalSpent: Double {
     expenses.reduce(0) { $0 + $1.amount }
     }*/
    var body: some View {
        NavigationStack {
            VStack(spacing: 20) {
                Text("PocketLedger")
                    .font(.largeTitle)
                    .fontWeight(.bold)
                
                Text("Total Spent")
                    .font(.headline)
                
                Text("₹\(totalSpent, specifier: "%.2f")")
                    .font(.system(size: 36, weight: .bold))
                
                NavigationLink("View Expenses") {
                    List {
                        ForEach($expenses) { $expense in
                            NavigationLink {
                                EditExpenseView(expense: $expense)
                            } label: {
                                HStack {
                                    VStack(alignment: .leading) {
                                        Text(expense.name)
                                            .font(.headline)

                                        Text(expense.category)
                                            .font(.caption)
                                            .foregroundStyle(.secondary)
                                    }

                                    Spacer()

                                    Text("₹\(expense.amount, specifier: "%.2f")")
                                }
                            }
                        }
                        .onDelete { indexSet in expenses.remove(atOffsets: indexSet)
                        }
                    }
                        .navigationTitle("Expenses")
                    }
                    NavigationLink("Add Expense") {
                        AddExpenseView(expenses: $expenses)
                    }
                }
                .padding()
                .navigationTitle("Home")
            }
        }
    }
    
    struct AddExpenseView: View {
        @Binding var expenses: [Expense]
        
        @State private var expenseName = ""
        @State private var amount = ""
        @State private var category = "Food"
        
        @Environment(\.dismiss) private var dismiss
        
        var body: some View {
            Form {
                TextField("Expense name", text: $expenseName)
                
                TextField("Amount", text: $amount)
                    .keyboardType(.decimalPad)
                
                Picker("Category", selection: $category) {
                    Text("Food").tag("Food")
                    Text("Transport").tag("Transport")
                    Text("Entertainment").tag("Entertainment")
                    Text("Other").tag("Other")
                }
                
                Button("Add Expense") {
                    guard !expenseName.isEmpty,
                          let amountValue = Double(amount) else {
                        return
                    }
                    
                    let newExpense = Expense(
                        name: expenseName,
                        amount: amountValue,
                        category: category
                    )
                    
                    expenses.append(newExpense)
                    
                    dismiss()
                }
            }
            .navigationTitle("Add Expense")
        }
    }
struct EditExpenseView: View {
    @Binding var expense: Expense

    @Environment(\.dismiss) private var dismiss

    var body: some View {
        Form {
            TextField("Expense name", text: $expense.name)

            TextField(
                "Amount",
                value: $expense.amount,
                format: .number
            )
            .keyboardType(.decimalPad)

            Picker("Category", selection: $expense.category) {
                Text("Food").tag("Food")
                Text("Transport").tag("Transport")
                Text("Entertainment").tag("Entertainment")
                Text("Other").tag("Other")
            }

            Button("Save Changes") {
                dismiss()
            }
        }
        .navigationTitle("Edit Expense")
    }
}
#Preview {
    ContentView()
}

/*List {
    HStack {
        Text("☕️")
        Text("Coffee")
        
        Spacer()
        
        Text("₹100")
    }
    HStack{
        Text("🏍️")
        Text("Fuel")
        Spacer()
        Text("₹200")
    }
    HStack {
        Text("🍱")
        Text("Food")
        
        Spacer()
        
        Text("₹150")
    }
    HStack {
        Text("🎬")
        Text("Movie")
        
        Spacer()
        
        Text("₹420")
    }
}*/

/*ForEach(expenses) { expense in
 HStack {
     Text(expense.name)

     Spacer()

     Text(expense.amount)
 }
}*/

/*NavigationLink("Add Expense") {
 Form {
     TextField("Expense name", text: $expenseName)
     
     TextField("Amount", text: $amount)
         .keyboardType(.decimalPad)
     
     Picker("Category", selection: $category) {
         Text("Food").tag("Food")
         Text("Transport").tag("Transport")
         Text("Entertainment").tag("Entertainment")
         Text("Other").tag("Other")
     }
     
     Button("Add Expense") {
         let newExpense = Expense(
             name: expenseName,
             amount: "₹\(amount)",
             category: category
         )

         expenses.append(newExpense)
         
         dismiss()
     }
 }
 .navigationTitle("Add Expense")
}*/
/*@State private var expenseName = ""
 @State private var category = "Food"
 @State private var amount = ""
 @Environment(\.dismiss) private var dismiss*/

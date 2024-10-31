<?php
// Initialize budget variables
$income = 0;
$expenses = [];
$expenseTotal = 0;
$balance = 0;

// Handle form submission
if ($_SERVER["REQUEST_METHOD"] === "POST") {
    if (isset($_POST['income'])) {
        $income = (float)$_POST['income'];
    }

    if (isset($_POST['expense_name']) && isset($_POST['expense_amount'])) {
        $expense_name = htmlspecialchars($_POST['expense_name']);
        $expense_amount = (float)$_POST['expense_amount'];
        
        if ($expense_name && $expense_amount > 0) {
            $expenses[] = ['name' => $expense_name, 'amount' => $expense_amount];
        }
    }

    // Calculate total expenses and balance
    foreach ($expenses as $expense) {
        $expenseTotal += $expense['amount'];
    }
    $balance = $income - $expenseTotal;
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
    <title>Simple Budget Planner</title>
    <style>
        body {
            background-color: #f8f9fa;
        }
        .container {
            max-width: 600px;
            margin-top: 50px;
        }
        .budget-summary {
            font-size: 1.25rem;
            font-weight: bold;
        }
    </style>
</head>
<body>

<div class="container">
    <h2 class="text-center mb-4">Simple Budget Planner</h2>

    <!-- Income Form -->
    <form method="POST">
        <div class="form-group">
            <label for="income">Monthly Income:</label>
            <input type="number" step="0.01" class="form-control" id="income" name="income" placeholder="Enter your income" value="<?php echo $income; ?>" required>
        </div>
        
        <!-- Expense Form -->
        <div class="form-group">
            <label for="expense_name">Expense Name:</label>
            <input type="text" class="form-control" id="expense_name" name="expense_name" placeholder="Enter expense name">
        </div>
        <div class="form-group">
            <label for="expense_amount">Expense Amount:</label>
            <input type="number" step="0.01" class="form-control" id="expense_amount" name="expense_amount" placeholder="Enter expense amount">
        </div>
        
        <button type="submit" class="btn btn-primary btn-block">Add Expense</button>
    </form>

    <!-- Budget Summary -->
    <div class="budget-summary mt-4">
        <p>Total Income: $<?php echo number_format($income, 2); ?></p>
        <p>Total Expenses: $<?php echo number_format($expenseTotal, 2); ?></p>
        <p>Balance: $<?php echo number_format($balance, 2); ?></p>
    </div>

    <!-- Expenses List -->
    <?php if (!empty($expenses)) : ?>
        <h4 class="mt-4">Expense Details:</h4>
        <ul class="list-group">
            <?php foreach ($expenses as $expense) : ?>
                <li class="list-group-item d-flex justify-content-between align-items-center">
                    <?php echo htmlspecialchars($expense['name']); ?>
                    <span>$<?php echo number_format($expense['amount'], 2); ?></span>
                </li>
            <?php endforeach; ?>
        </ul>
    <?php endif; ?>
</div>

<script src="https://code.jquery.com/jquery-3.5.1.slim.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.9.2/dist/umd/popper.min.js"></script>
<script src="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js"></script>
</body>
</html>

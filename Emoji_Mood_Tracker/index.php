<?php
// File to store mood history
$file = "mood_history.txt";

// Check if the mood was submitted
if (isset($_POST['mood'])) {
    $mood = $_POST['mood'];
    $date = date("Y-m-d H:i:s");
    
    // Save mood and date to file
    $entry = "$date - $mood\n";
    file_put_contents($file, $entry, FILE_APPEND | LOCK_EX);
    $message = "Your mood has been recorded!";
}

// Read mood history from file
$moodHistory = file_exists($file) ? file($file, FILE_IGNORE_NEW_LINES) : [];

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Emoji Mood Tracker</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
    <style>
        .container {
            margin-top: 50px;
        }
        .mood-btn {
            font-size: 2rem;
            margin: 5px;
        }
        .mood-history {
            max-height: 200px;
            overflow-y: auto;
        }
    </style>
</head>
<body>
    <div class="container text-center">
        <h1>Emoji Mood Tracker</h1>
        <p>Select an emoji that represents your current mood:</p>

        <?php if (isset($message)): ?>
            <div class="alert alert-success"><?php echo $message; ?></div>
        <?php endif; ?>

        <!-- Mood Selection Form -->
        <form method="POST">
            <button type="submit" name="mood" value="😊" class="btn btn-light mood-btn">😊</button>
            <button type="submit" name="mood" value="😐" class="btn btn-light mood-btn">😐</button>
            <button type="submit" name="mood" value="😢" class="btn btn-light mood-btn">😢</button>
            <button type="submit" name="mood" value="😠" class="btn btn-light mood-btn">😠</button>
            <button type="submit" name="mood" value="😎" class="btn btn-light mood-btn">😎</button>
        </form>

        <!-- Display Mood History -->
        <div class="mt-4">
            <h3>Mood History</h3>
            <div class="mood-history border p-3">
                <?php if (!empty($moodHistory)): ?>
                    <ul class="list-unstyled">
                        <?php foreach ($moodHistory as $entry): ?>
                            <li><?php echo htmlspecialchars($entry); ?></li>
                        <?php endforeach; ?>
                    </ul>
                <?php else: ?>
                    <p>No mood history available yet.</p>
                <?php endif; ?>
            </div>
        </div>
    </div>

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/js/bootstrap.bundle.min.js"></script>
</body>
</html>

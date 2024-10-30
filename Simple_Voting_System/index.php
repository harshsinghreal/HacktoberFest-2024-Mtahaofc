<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Simple Voting System</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
    <style>
        .container {
            margin-top: 50px;
        }
        .vote-count {
            font-size: 1.2rem;
            color: #333;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1 class="text-center">Simple Voting System</h1>
        <p class="text-center">Vote for your favorite option below:</p>

        <?php
        // File to store vote counts
        $file = "votes.txt";

        // Initialize votes if the file doesn't exist
        if (!file_exists($file)) {
            $votes = ["Option A" => 0, "Option B" => 0];
            file_put_contents($file, json_encode($votes));
        } else {
            $votes = json_decode(file_get_contents($file), true);
        }

        // Handle voting
        if ($_SERVER['REQUEST_METHOD'] === 'POST') {
            $vote = $_POST['vote'];
            if (array_key_exists($vote, $votes)) {
                $votes[$vote]++;
                file_put_contents($file, json_encode($votes));
                echo '<div class="alert alert-success text-center">Thank you for voting!</div>';
            } else {
                echo '<div class="alert alert-danger text-center">Invalid vote option.</div>';
            }
        }
        ?>

        <form method="POST" class="text-center my-4">
            <button type="submit" name="vote" value="Option A" class="btn btn-primary mx-2">Vote for Backend</button>
            <button type="submit" name="vote" value="Option B" class="btn btn-secondary mx-2">Vote for Frontend</button>
        </form>

        <div class="text-center">
            <h3>Current Vote Count</h3>
            <p class="vote-count">Backend: <?php echo $votes["Option A"]; ?> votes</p>
            <p class="vote-count">Frontend: <?php echo $votes["Option B"]; ?> votes</p>
        </div>
    </div>

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/js/bootstrap.bundle.min.js"></script>
</body>
</html>

<?php
    session_start();
    if((isset($_SESSION['signed_in'])) && ($_SESSION['signed_in'] == true)) {
        header('Location: listy.php');
        exit();
     }
?>

<!DOCTYPE HTML>
<head>
    <title>Strona glowna</title>
    <link rel="stylesheet" href="style.css" type="text/css" />
</head>
<body>
    <div class="content">
    <form action="logowanie.php" method="post">
        Login: <br /> <input type="text" name="login" title="login"/> <br/>
        Hasło: <br /> <input type="password" name="haslo" title="haslo"/> <br/><br/>
        <input type="submit" value="Zaloguj się" />
    </form>

    <?php
        if(isset($_SESSION['sign_in_error'])) {
            echo $_SESSION['sign_in_error'];
            unset($_SESSION['sign_in_error']);
        }

    ?>
    </div>
</body>
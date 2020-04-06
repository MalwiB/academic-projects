<?php
session_start();
if(!isset($_SESSION['signed_in'])) {
    header('Location: index.php');
    exit();
}

?>

<head>
    <link rel="stylesheet" href="style.css" type="text/css" />
</head>

<body>

<ul class="ul_bar">
    <li class="li_bar"><a href="wyszukiwarka.php">Wyszukiwarka</a></li>
    <li class="li_bar"><a href="listy.php">Moje listy</a></li>
    <li class="li_bar"><a class="active" href="dodawanie_albumu.php">Dodawanie albumu</a></li>
    <li class="li_bar"><a href="top.php">Top 20</a></li>
    <li class="li_bar" style="float:right"><a href="wylogowywanie.php">Wylogowywanie</a></li>
</ul>


<div class="content">

    <h1>Dodaj album</h1>

<form action="dodawanie_albumu_do_bazy.php" method="post">

    <br><br>
    Nazwa: <input type="text" name="nazwa_albumu" title="nazwa albumu" > *
    <br><br>

    Zespol: <input type="text" name="nazwa_zespolu" title="nazwa zespolu"> *
    <br><br>

    Rok wydania: <input type="text" name="rok_wydania" title="rok wydania"> *
    <br><br>

    Gatunek: <input type="text" name="gatunek" title="gatunek">
    <br><br>

    <input type="submit" value="Zatwierdz"/>

    <?php
    if(isset($_SESSION['add_album_comm'])) {
        echo $_SESSION['add_album_comm'];
        unset($_SESSION['add_album_comm']);
    }
    ?>

</form>

    </div>

</body>

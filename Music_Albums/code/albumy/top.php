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
    <li class="li_bar"><a href="dodawanie_albumu.php">Dodawanie albumu</a></li>
    <li class="li_bar"><a class="active" href="top.php">Top 20</a></li>
    <li class="li_bar" style="float:right"><a href="wylogowywanie.php">Wylogowywanie</a></li>
</ul>


<div class="content">

    <h1>Top 20 albumów</h1>


<?php

require "dane_logowania.php";

$connection = @new mysqli($host, $db_user, $db_password, $db_name);

if($connection->connect_errno != 0) {
    echo "Error: ".$connection->connect_errno."Opis: ".$connection->connect_error;
}
else {
        $query = "SELECT id_a, nazwa, zespol, rok, gatunek, ocena FROM albumy ORDER BY ocena DESC LIMIT 20";
        $result = @$connection->query($query);
        $number_of_albums = $result->num_rows;
        if ($number_of_albums > 0) {
            echo "<table border='0'><tr><th>Nazwa</th><th>Zespol</th><th>Rok</th><th>Gatunek</th><th>Ocena</th></tr>";
            while ($row = $result->fetch_assoc()) {
                $id_a = $row['id_a'];
                $nazwa = $row['nazwa'];
                $zespol = $row['zespol'];
                $rok = $row['rok'];
                $gatunek = $row['gatunek'];
                $ocena = $row['ocena'];
                echo "<tr><td>$nazwa</td><td>$zespol</td><td>$rok</td><td>$gatunek</td><td>$ocena</td>";
            }
            echo "</table>";
        }
        $result->free();

}


?>
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
    <li class="li_bar"><a class="active" href="listy.php">Moje listy</a></li>
    <li class="li_bar"><a href="dodawanie_albumu.php">Dodawanie albumu</a></li>
    <li class="li_bar"><a href="top.php">Top 20</a></li>
    <li class="li_bar" style="float:right"><a href="wylogowywanie.php">Wylogowywanie</a></li>
</ul>


<div class="content">

    <h1>Moje listy</h1>

<form action="dodaj_liste.php" method="post">

    DODAJ LISTĘ:  <input type="text" name="nazwa_listy" title="nazwa listy">
    <?php
    if(isset($_SESSION['add_list_error'])) {
        echo $_SESSION['add_list_error'];
    }
    ?>
    <input type="submit" value="Dodaj">


<br><br>
<?php

require "dane_logowania.php";

$connection = @new mysqli($host, $db_user, $db_password, $db_name);

if($connection->connect_errno != 0) {
    echo "Error: ".$connection->connect_errno."Opis: ".$connection->connect_error;
}
else {
    $user_id = $_SESSION['user_id'];
    $query_lists = "SELECT id_lis, nazwa, ilosc_el FROM listy where id_uz='$user_id'";
    if ($result_list = @$connection->query($query_lists)) {
        while($row = $result_list->fetch_assoc()) {
            $id_lis = $row['id_lis'];
            echo "<b>".$row['nazwa']."</b>".": <a class='a_delete' href=\"usuwanie_listy.php?id_lis=$id_lis\">[ usuń ]</a>";
            echo "<br>";
            $query_list_element = "SELECT id_a FROM elementy_list where id_lis='$id_lis'";
            if ($result_element = @$connection->query($query_list_element)) {
                while ($row_album = $result_element->fetch_assoc()) {
                    $id_a = $row_album['id_a'];
                    $query_album = "SELECT nazwa, zespol, rok, ocena FROM albumy where id_a='$id_a'";
                    $result_album = @$connection->query($query_album);
                    $row_album = $result_album->fetch_assoc();
                    $nazwa = $row_album['nazwa'];
                    $zespol = $row_album['zespol'];
                    $rok = $row_album['rok'];
                    $ocena = $row_album['ocena'];
                    echo "$nazwa    -     $zespol    -   $rok   -   $ocena";
                    echo " <a class='a_delete' href=\"usuwanie_z_listy.php?id_a=$id_a&id_lis=$id_lis\">[ x ]</a>";
                    echo "<br>";
                }

            }
            echo "<br>";

        }
    }
    else {

    }
}

?>

</div>
</body>
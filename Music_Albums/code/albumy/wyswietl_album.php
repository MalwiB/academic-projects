<?php
session_start();
if(!isset($_SESSION['signed_in'])) {
    header('Location: index.php');
    exit();
}

require "dane_logowania.php";

$connection = @new mysqli($host, $db_user, $db_password, $db_name);

$po_czym = $_GET['po_czym'];
$value = $_GET['value'];
$id_a = $_GET['id_a'];
?>


    <head>
        <link rel="stylesheet" href="style.css" type="text/css" />
    </head>
    <body>

    <ul class="ul_bar">
        <li class="li_bar"><a href="wyszukiwarka.php">Wyszukiwarka</a></li>
        <?php
        echo "<li class='li_bar'><a href=wyszukiwanie_w_bazie.php?id_a=".$id_a."&po_czym=".$po_czym."&value=".$value.">Wyniki wyszukiwania</a></li>";
        ?>
        <li class="li_bar"><a href="listy.php">Moje listy</a></li>
        <li class="li_bar"><a href="dodawanie_albumu.php">Dodawanie albumu</a></li>
        <li class="li_bar" style="float:right"><a href="wylogowywanie.php">Wylogowywanie</a></li>
    </ul>
    <br>

    <div class="left">


<?php
if($connection->connect_errno != 0) {
    echo "Error: ".$connection->connect_errno."Opis: ".$connection->connect_error;
}
else {
    $query = "SELECT id_a, nazwa, zespol, rok, gatunek, ocena FROM albumy WHERE id_a=$id_a";
    if ($result = @$connection->query($query)) {
        $row = $result->fetch_assoc();
        $id_a = $row['id_a'];
        $nazwa = $row['nazwa'];
        $zespol = $row['zespol'];
        $rok = $row['rok'];
        $gatunek = $row['gatunek'];
        $ocena = $row['ocena'];
        echo "<h2>$nazwa</h2>";
        echo "Zespół: <b>$zespol</b><br>";
        echo "Rok wydania: <b>$rok</b><br>";
        echo "Gatunek: <b>$gatunek</b><br>";
        echo "Ocena: <b>$ocena</b><br>";

        echo "<br><u>Piosenki w albumie:</u><br><ul style=\"list-style-type:disc\">";
        $query_piosenki = "SELECT * from piosenki WHERE id_a=$id_a";
        if ($result_piosenki = @$connection->query($query_piosenki)) {
            while ($row = $result_piosenki->fetch_assoc()) {
                $id_uz = $_SESSION['user_id'];
                $id_p = $row['id_p'];
                $nazwa = $row['nazwa'];
                $dlugosc = $row['dlugosc'];
                $ocena = $row['ocena_p'];
                echo "<li><b>$nazwa</b><ul><li>Czas trwania: <b>$dlugosc</b></li><li>Ocena: <b>$ocena</b></li>";

                $query_oceniona = "SELECT wartosc FROM oceny WHERE id_p=$id_p AND id_uz=$id_uz";
                $result_oceniona = @$connection->query($query_oceniona);
                if ($result_oceniona->num_rows) {
                    $row = $result_oceniona->fetch_assoc();
                    $ocena = $row['wartosc'];
                    echo "<li>Twoja ocena: <b>$ocena</b><br><br>";
                }
                else {
                    echo "<form action='ocen_piosenke.php?id_a=$id_a&id_p=$id_p&po_czym=$po_czym&value=$value' method='post'>";
                    echo "<li>Twoja ocena: ";
                    for ($i=1; $i<=10; $i++)
                        echo "<input type='radio' name='ocena' value='$i'>$i ";
                    echo "<input type='submit' value='Ocen'>";
                    echo "</form>";
                }
                echo "</li></ul></li>";

            }
        }
        echo "</ul>";
    }
?>
    </div>
    <div class="right">


        <?php
    $id_uz = $_SESSION['user_id'];
    $query_listy = "SELECT id_lis, nazwa FROM listy WHERE id_uz=$id_uz";
    $result_listy = @$connection->query($query_listy);


    echo "<br><br>Dodaj piosenkę do albumu: ";
    echo "<form action='dodaj_piosenke.php?id_a=$id_a&po_czym=$po_czym&value=$value' method='post'>";
    echo 'Nazwa: <input type="text" name="nazwa_piosenki" title="nazwa piosenki" > *<br>';
    echo 'Dlugosc: <input type="text" name="dlugosc_piosenki" title="dlugosc piosenki" ><br><br>';
    echo '<input type="submit" value="Dodaj piosenke"/>';
    echo "</form>";



    echo "<br><br>Dodaj album do listy: ";
    echo "<form action='dodaj_do_listy.php?id_a=$id_a&po_czym=$po_czym&value=$value' method='post'>";
    echo "<select name='do_listy' title='do_listy'>";

    while($row = $result_listy->fetch_assoc()) {
        $nazwa = $row['nazwa'];
        $id_lis = $row['id_lis'];
        echo "<option value='$id_lis'>$nazwa</option>";
    }

    echo "</select><br><br>";
    echo "<input type='submit' value='Dodaj'>";
    // domykac form.... -_-
    echo "</form>";

}

?>

        </div>

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
        <li class="li_bar"><a class="active" href="wyszukiwarka.php">Wyszukiwarka</a></li>
        <li class="li_bar"><a href="listy.php">Moje listy</a></li>
        <li class="li_bar"><a href="dodawanie_albumu.php">Dodawanie albumu</a></li>
        <li class="li_bar"><a href="top.php">Top 20</a></li>
        <li class="li_bar" style="float:right"><a href="wylogowywanie.php">Wylogowywanie</a></li>
    </ul>
    <br><br>

    <div class="content">

<?php
require "dane_logowania.php";

$connection = @new mysqli($host, $db_user, $db_password, $db_name);

if($connection->connect_errno != 0) {
    echo "Error: ".$connection->connect_errno."Opis: ".$connection->connect_error;
}
else {

    echo "<head> <link rel=\"stylesheet\" href=\"style.css\" type=\"text/css\" /></head>";

    if(isset($_POST['wyszukuj_po']) && isset($_POST['value'])) {
        $po_czym = $_POST['wyszukuj_po'];
        $value = $_POST['value'];
    }
    else {
        $po_czym = $_GET['po_czym'];
        $value = $_GET['value'];
    }
    if ($po_czym == 'nazwa') {
        $query = "SELECT id_a, nazwa, zespol, rok, gatunek, ocena FROM albumy WHERE nazwa='$value'";
        $result = @$connection->query($query);
        $number_of_albums = $result->num_rows;
        if ($number_of_albums == 0) {
            $_SESSION['wyszukaj'] = '<br><br><p style="color:red">W bazie nie ma takiego albumu.</p>';
            header('Location:wyszukiwarka.php');
        }
        if ($number_of_albums > 0) {
            echo "<table border='0'><tr><th>Nazwa</th><th>Zespol</th><th>Rok</th><th>Gatunek</th><th>Ocena</th><th></th></tr>";
            while ($row = $result->fetch_assoc()) {
                $id_a = $row['id_a'];
                $nazwa = $row['nazwa'];
                $zespol = $row['zespol'];
                $rok = $row['rok'];
                $gatunek = $row['gatunek'];
                $ocena = $row['ocena'];
                echo "<tr><td>$nazwa</td><td>$zespol</td><td>$rok</td><td>$gatunek</td><td>$ocena</td>";
                echo "<td><a class='a_szczegoly' href=\"wyswietl_album.php?id_a=$id_a&po_czym='$po_czym'&value='$value'\">szczegóły...</a></td></tr>";
            }
            echo "</table>";
        }
        $result->free();
    }
    else if ($po_czym == 'zespol') {
        $query = "SELECT id_a, nazwa, zespol, rok, gatunek, ocena FROM albumy WHERE zespol='$value'";
        $result = @$connection->query($query) ;
        $number_of_albums = $result->num_rows;
        if ($number_of_albums == 0) {
            $_SESSION['wyszukaj'] = '<br><br><p style="color:red">W bazie nie ma takiego albumu.</p>';
            header('Location:wyszukiwarka.php');
        }
        if ($number_of_albums > 0) {
            echo "<table border='0'><tr><th>Nazwa</th><th>Zespol</th><th>Rok</th><th>Gatunek</th><th>Ocena</th><th></th></tr>";
            while ($row = $result->fetch_assoc()) {
                $id_a = $row['id_a'];
                $nazwa = $row['nazwa'];
                $zespol = $row['zespol'];
                $rok = $row['rok'];
                $gatunek = $row['gatunek'];
                $ocena = $row['ocena'];
                echo "<tr><td>$nazwa</td><td>$zespol</td><td>$rok</td><td>$gatunek</td><td>$ocena</td>";
                echo "<td><a class='a_szczegoly' href=\"wyswietl_album.php?id_a=$id_a&po_czym=$po_czym&value=$value\">szczegóły...</a></td></tr>";
            }
            echo "</table>";
        }
        $result->free();
    }
    else if ($po_czym == 'rok') {
        $query = "SELECT id_a, nazwa, zespol, rok, gatunek, ocena FROM albumy WHERE rok='$value'";
        $result = @$connection->query($query) ;
        $number_of_albums = $result->num_rows;
        if ($number_of_albums == 0) {
            $_SESSION['wyszukaj'] = '<br><br><p style="color:red">W bazie nie ma takiego albumu.</p>';
            header('Location:wyszukiwarka.php');
        }
        if ($number_of_albums > 0) {
            echo "<table border='0'><tr><th>Nazwa</th><th>Zespol</th><th>Rok</th><th>Gatunek</th><th>Ocena</th><th></th></tr>";
            while ($row = $result->fetch_assoc()) {
                $id_a = $row['id_a'];
                $nazwa = $row['nazwa'];
                $zespol = $row['zespol'];
                $rok = $row['rok'];
                $gatunek = $row['gatunek'];
                $ocena = $row['ocena'];
                echo "<tr><td>$nazwa</td><td>$zespol</td><td>$rok</td><td>$gatunek</td><td>$ocena</td>";
                echo "<td><a class='a_szczegoly' href=\"wyswietl_album.php?id_a=$id_a&po_czym=$po_czym&value=$value\">szczegóły...</a></td></tr>";
            }
            echo "</table>";
        }
        $result->free();
    }


}


$connection->close();

?>
        </div>
    </body>

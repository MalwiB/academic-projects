<?php
session_start();
if(!isset($_SESSION['signed_in'])) {
    header('Location: index.php');
    exit();
}

require "dane_logowania.php";

$connection = @new mysqli($host, $db_user, $db_password, $db_name);

if($connection->connect_errno != 0) {
    echo "Error: ".$connection->connect_errno."Opis: ".$connection->connect_error;
}
else {
    $nazwa_albumu = $_POST['nazwa_albumu'];
    $zespol = $_POST['nazwa_zespolu'];
    $rok = $_POST['rok_wydania'];
    $gatunek = $_POST['gatunek'];

    $query = "SELECT * FROM albumy WHERE nazwa='$nazwa_albumu' AND zespol='$zespol' AND rok='$rok'";
    $result = @$connection->query($query) ;
    $number_of_albums = $result->num_rows;
    if ($number_of_albums > 0) {
        $_SESSION['add_album_comm'] = '<br><br><p style="color:red">Album juz istnieje w bazie!</p>';
        header('Location: dodawanie_albumu.php');
    }
    else {

        $query = "INSERT INTO albumy (nazwa, zespol, rok, gatunek, ocena) VALUES ('$nazwa_albumu', '$zespol', '$rok', '$gatunek', 0)";

        if (@$connection->query($query)) {
            $_SESSION['add_album_comm'] = '<br><br>' . 'Album dodany do bazy.';
            header('Location: dodawanie_albumu.php');
        } else {
            $_SESSION['add_album_comm'] = '<br><br><p style="color:red">Blednie uzupelnione dane albumu!</p>';
            header('Location: dodawanie_albumu.php');
        }
    }
}

?>

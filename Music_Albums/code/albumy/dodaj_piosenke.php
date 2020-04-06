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

    $po_czym = $_GET['po_czym'];
    $value = $_GET['value'];

    $nazwa = $_POST['nazwa_piosenki'];
    $dlugosc = $_POST['dlugosc_piosenki'];
    $id_a = $_GET['id_a'];

    $query = "INSERT INTO piosenki (nazwa, dlugosc, suma_ocen, ilosc_ocen, ocena_p, id_a) VALUES ('$nazwa', '$dlugosc', 0, 0, 0, '$id_a')";
    if (@$connection->query($query)) {
        header("Location: wyswietl_album.php?id_a=$id_a&po_czym=$po_czym&value=$value");
    }
}
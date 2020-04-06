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

    $id_a = $_GET['id_a'];
    $id_lis = $_POST['do_listy'];
    //sprawdzanie czy takiego powiazania juz nie ma
    $query = "INSERT INTO elementy_list (id_a, id_lis) VALUES ($id_a, $id_lis)";
    if (@$connection->query($query)) {
        $query2 = "UPDATE listy SET ilosc_el=ilosc_el+1 WHERE id_lis=$id_lis";
        if (@$connection->query($query2)) {

            header("Location: wyswietl_album.php?id_a=$id_a&po_czym=$po_czym&value=$value");
        }
    }
}

?>

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

    // do powrotu
    $po_czym = $_GET['po_czym'];
    $value = $_GET['value'];

    $id_uz = $_SESSION['user_id'];
    $id_a = $_GET['id_a'];
    $id_p = $_GET['id_p'];
    $wartosc = $_POST['ocena'];
    $query = "INSERT INTO oceny (wartosc, id_uz, id_p) VALUES ($wartosc, $id_uz, $id_p)";
    if (@$connection->query($query)) {
        $query2 = "UPDATE piosenki SET suma_ocen=suma_ocen+$wartosc, ilosc_ocen=ilosc_ocen+1, ocena_p=suma_ocen/ilosc_ocen where id_p=$id_p";
        if (@$connection->query($query2)) {
            $query3 = "SELECT suma_ocen, ilosc_ocen from piosenki WHERE id_a=$id_a";
            if ($result2 = @$connection->query($query3)) {
                $suma = $ilosc = 0;
                while ($row = $result2->fetch_assoc()) {
                    $suma += $row['suma_ocen'];
                    $ilosc += $row['ilosc_ocen'];
                }
                $nowa_ocena = $suma / $ilosc;

                $query4 = "UPDATE albumy SET ocena=$nowa_ocena where id_a=$id_a";
                if (@$connection->query($query4)) {
                    header("Location: wyswietl_album.php?id_a=$id_a&po_czym=$po_czym&value=$value");
                }
            }
        }
    }


}
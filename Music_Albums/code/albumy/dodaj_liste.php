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
    $nazwa_listy = $_POST['nazwa_listy'];
    $user_id = $_SESSION['user_id'];
    $query = "INSERT INTO listy (nazwa, ilosc_el, id_uz) VALUES ('$nazwa_listy', 0, '$user_id')";
    if (@$connection->query($query)) {
        header('Location: listy.php');
    } else {
        $_SESSION['add_list_error'] = '<br><br>' . ' Dodawanie listy nie powiodło się.';
        header('Location: listy.php');
    }
}


?>
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
    $id_lis = $_GET['id_lis'];
    $query = "DELETE FROM elementy_list where id_lis=$id_lis";
    if ($result = @$connection->query($query)) {
        $query = "DELETE FROM listy where id_lis=$id_lis";
        if ($result = @$connection->query($query)) {
            header('Location: listy.php');
        }
    }
    else {
    $_SESSION['add_list_error'] = '<br><br>' . 'Usuwanie listy nie powiodło się.';
    header('Location: listy.php');
    }

}

?>
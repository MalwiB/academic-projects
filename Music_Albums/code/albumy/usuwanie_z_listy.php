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
    $id_a = $_GET['id_a'];
    $id_lis = $_GET['id_lis'];
    $query1 = "DELETE FROM elementy_list WHERE id_lis=$id_lis AND id_a=$id_a";
    if ($result = @$connection->query($query1)) {
        $query2 = "UPDATE listy SET ilosc_el=ilosc_el-1 WHERE id_lis=$id_lis";
        if ($result = @$connection->query($query2)) {
            header('Location: listy.php');
        }
    }
    else {
        $_SESSION['add_list_error'] = '<br><br>' . 'Usuwanie listy nie powiodło się.';
        header('Location: listy.php');
    }

}

?>
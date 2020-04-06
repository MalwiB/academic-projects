<?php
    session_start();

	require "dane_logowania.php";
	
	$connection = @new mysqli($host, $db_user, $db_password, $db_name);
	
	if($connection->connect_errno != 0) {
		echo "Error: ".$connection->connect_errno."Opis: ".$connection->connect_error;
	}
	else {
		$login = $_POST['login'];
		$password = addslashes($_POST['haslo']);
		
		$query = "SELECT * FROM uzytkownicy WHERE login='$login' AND haslo='$password'";

		if($result = @$connection->query($query)) {
            $users_number = $result->num_rows;
            if ($users_number > 0) {
                $row = $result->fetch_assoc();

                $_SESSION['signed_in'] = true;
                $_SESSION['user_id'] = $row['id_uz'];
                $_SESSION['login'] = $row['login'];
                $user = $row['login'];

                unset($_SESSION['sign_in_error']);

                $result->free_result();

                header('Location: wyszukiwarka.php');

            } else {
                $_SESSION['sign_in_error'] = '<br />'.'Nie ma uzytkownika o podanym loginie i hasle!';
                header('Location: index.php');
            }
        }

        $connection->close();
	}

?>
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


<div class="content">


<h1>Wyszukiwarka</h1>
<form action="wyszukiwanie_w_bazie.php" method="post">

    <br>
    Wyszukaj album po:
    <select name="wyszukuj_po" title="wyszukuj_po">
        <option value="nazwa">nazwie</option>
        <option value="zespol">zespole</option>
        <option value="rok">roku wydania</option>
        <!---<option value="piosenka">nazwie piosenki</option>-->
    </select>

    <br><br>
    <input type="text" name="value" title="value" autocomplete="off">

    <br><br>
    <input type="submit" value="Wyszukaj" title="wyszukaj" >


    <?php
    if(isset($_SESSION['wyszukaj'])) {
        echo $_SESSION['wyszukaj'];
        unset($_SESSION['wyszukaj']);
    }
    ?>



    </div>

</body>

<!DOCTYPE html>
<?php
include('parametri.php');
?>
<html>
    <head>
        <meta charset="UTF-8">
        <title><?= $GLOBALS['APPNAME'] ?> - Home</title>
        <link rel="stylesheet" type="text/css" href="stile1.css"/>
    </head>
    <body background='migliore-frutta-verdura.jpg'>
        <?php include('header.php');?>
        <div class="centra benvenu">
            <b>Benvenuto <?=$_SESSION['user']['nome']?> <?=$_SESSION['user']['cognome']?> alla Home Page del sito<br><br>
                Qui puoi selezionare con quale utente entrare:</b><br><br>
                <button class='button1' onclick="window.location='hp_acquirente.php'"><b>Acquirente</b></button> <button class='button1' onclick="window.location='hp_venditore.php'"><b>Venditore</b></button>
        </div>
    </body>
</html>
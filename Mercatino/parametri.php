<?php
$APPNAME = 'FoodMark';

$DB_SERVER = 'localhost';
$DB_USER = 'testuser';
$DB_PASSWORD = 'Antonio69.';
$DB_SCHEMA = 'test';

$MYDB = @mysqli_connect($DB_SERVER, $DB_USER, $DB_PASSWORD, $DB_SCHEMA);
if ($MYDB===FALSE) {
    die ('Errore nella connessione al DB');
}

session_start();
?>
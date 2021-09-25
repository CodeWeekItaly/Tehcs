<!DOCTYPE html>
<?php
include('parametri.php');
?>
<html>
    <head>
        <meta charset="UTF-8">
        <title><?= $GLOBALS['APPNAME'] ?></title>
        <link rel="stylesheet" type="text/css" href="stile1.css"/>
    </head>
    <body>
        <?php 
        if (($_POST['nome']!='') && ($POST['cognome']!='') && ($_POST['username']!='') && ($_POST['password']!='') && ($_POST['email']!='')) {
            if (filter_var($_POST['email'], FILTER_VALIDATE_EMAIL)) {
                if (strlen($_POST['password'])>7) {
                    $query = "select * from utenti where username='". mysqli_escape_string($GLOBALS['MYDB'], $_POST['username']) ."'";
                    if ($res = mysqli_query($GLOBALS, $query)) {
                        if ($user = mysqli_fetch_assoc($GLOBALS['MYDB'], $res)) {
                            echo "Esiste già un utente con questo username.<br><br>Torna e modifica il <a href='javascript:window.history.back();'>modulo di registrazione</a>";
                        }
                        else {
                            $query2 = "insert into utenti (nome,cognome,username,password,email) values (";
                            $query2 .= "'" . mysqli_escape_string($GLOBALS['MYDB'], $_POST['nome']) . "'," ;
                            $query2 .= "'" . mysqli_escape_string($GLOBALS['MYDB'], $_POST['cognome']) . "'," ;
                            $query2 .= "'" . mysqli_escape_string($GLOBALS['MYDB'], $_POST['username']) . "'," ;
                            $query2 .= "'" . md5($_POST['password']) . "'," ;
                            $query2 .= "'" . mysqli_escape_string($GLOBALS['MYDB'], $_POST['email']) . "')" ;
                            
                            if ($reg = mysqli_query($GLOBALS['MYDB'], $query2)) {
                                ?>
                                <script>
                                    alert("Registrazione completata con successo!");
                                    windows.location('userlogin.php');
                                </script>
                                <?php
                            }
                            else {
                                echo "<b>Errore nella registrazione! Si prega di riprovare</b>";
                            }
                        }
                    }
                }
                else {
                    echo "La password deve essere di almeno 8 caratteri.<br><br>Torna e completa il <a href='javascript:window.history.back();'>modulo di registrazione</a>";
                }
            }
            else {
                echo "L'indirizzo e-mail non è valido.<br><br>Torna e completa il <a href='javascript:window.history.back();'>modulo di registrazione</a>";
            }
        }
        else {
            echo "Tutti i campi sono obbligatori<br><br>Torna e completa il <a href='javascript:window.history.back();'>modulo di registrazione</a>";
        }
        ?>
    </body>
</html>


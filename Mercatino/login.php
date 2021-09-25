<!DOCTYPE html>
<?php
include('parametri.php');
?>
<html>
    <head>
        <meta charset="UTF-8">
        <title><?= $GLOBALS['APPNAME'] ?> - Login</title>
        <link rel="stylesheet" type="text/css" href="stile1.css"/>
    </head>
    <body background='migliore-frutta-verdura.jpg'>
        <?php
        include('header.php');
        $nomeutente = mysqli_escape_string($MYDB, $_POST['username']);
        $query = "select u.*, v.ragione_sociale, v.codice_fiscale from utenti u left join venditori v on u.id_venditore= v.id where username='{$nomeutente}'";
        $myres = mysqli_query($MYDB, $query);
        if ($myres!==FALSE) {
            $utente = mysqli_fetch_assoc($myres);
            if ($utente!=FALSE) {
                $password= md5($_POST['password']);
                if ($password===$utente['password']) {
                    $_SESSION['user']=$utente;
                    if (is_null($utente['id_venditore'])) {
                        echo 'login effettuato<br><br><a href="index.php">torna alla homepage</a>';
                    } else { ?>
                        <script language='javascript'>
                            window.location='scelta.php';
                        </script>
                    <?php
                    }
                } else {
                    echo 'password errata';
                }
            } else {
                echo 'username errato';                
            }
        }
        else {
            die('errore esecuzione query');
        }
        ?>
    </body>
</html>
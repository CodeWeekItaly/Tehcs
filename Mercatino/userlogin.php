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
        <?php include('header.php'); ?>
        <div class="login">
            <?php if (!isset($_SESSION['user'])) {?>
            <form action="login.php" method="post">
                <table align='center' class='benve1'> 
                    <tr>
                        <td>Nome utente:</td>
                        <td><input type="text" name="username"></td>
                    </tr>
                    <tr>
                        <td>Password:</td>
                        <td><input type="password" name="password"></td>
                    </tr>
                    <tr class='centra'>
                        <td colspan="2"><input class='button' type='submit' value='login'>&nbsp;&nbsp;<input class='button' type='reset' value='azzera'></td>
                    </tr>
                </table>
                
            </form>
            <?php } 
            else { 
                ?>
                <script language='javascript'>
                <?php
                if (@$_SESSION['user']['id_venditore']) {
                    echo "window.location='scelta.php'";
                }
                else {
                    echo "window.location='hp_acquirente.php'";
                }
                ?>
                </script><?php
            } 
            ?>
        </div>
    </body>
</html>

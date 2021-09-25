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
    <body background="migliore-frutta-verdura.jpg">
        <?php include('header.php'); ?>
        <form action='registrazione.php' method='POST'>
            <div class='login'>
        <table  align='center'>
            <tr>
                <td colspan="2"><b>Registrazione</b></td>
            </tr>
            <tr>
                <td align='right'>NOME</td>
                <td><input type="text" name="nome"></td>
            </tr>
            <tr>
                <td align='right'>COGNOME</td>
                <td><input type="text" name="cognome"></td>
            </tr>
            <tr>
                <td align='right'>USERNAME</td>
                <td><input type="text" name="username"></td>
            </tr>
            <tr>
                <td align='right'>PASSWORD</td>
                <td><input type="password" name="password"></td>
            </tr>
            <tr>
                <td align='right'>EMAIL</td>
                <td><input type="text" name="email"></td>
            </tr>            
            <tr>
                <td align='right'>Sei un venditore?</td>
                <td><input type="checkbox" name="vendor"></td>
            </tr>
            <tr>
                <td colspan='2' align='center'><input type='submit' value='REGISTER' class='button'>&nbsp;&nbsp;<input type='reset' class='button' value='RESET'></td>
            </tr>
        </table>
            </div>
        </form>
    </body>
</html>


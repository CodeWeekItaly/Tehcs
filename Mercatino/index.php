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
        <?php include ('header.php');?>
        <table align='center' style="margin-top: 40vh;">
            <tr>
                <td colspan="2" class="benvenuto"><span>Benvenuto nel nostro sito<br><br></span></td>              
            </tr>
            <tr>
                <td><button class="button1" onclick="window.location='userlogin.php'"><b>ACCEDI</b></button></td>
                <td><button class="button1" onclick="window.location='register.php'"><b>REGISTRATI</b></button></td>                
            </tr>
        </table>
    </body>
</html>

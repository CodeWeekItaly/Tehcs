<script src="jquery.js"></script>
<div class="header">
    <?php if (isset($_SESSION['user'])) : ?><div class="hambmenu" id="hambmenu">&#x2630;</div><?php endif; ?><?= $GLOBALS['APPNAME'] ?>
    <div class="hambmenu_m" id="hambmenu_m">
        <?php if (@$_SESSION['user']['id_venditore']) : ?>
        <a href="scelta.php">cambia ruolo</a><br>
        <?php endif; ?>
        <a href="logout.php">logout</a>
    </div>
</div>

<script language="javascript">
$(document).ready(function(){
    $('#hambmenu').click(function(){
        $('#hambmenu_m').show(100);
    });
    $('#hambmenu_m').click(function(){
        $('#hambmenu_m').hide(100);
    });
});
</script>
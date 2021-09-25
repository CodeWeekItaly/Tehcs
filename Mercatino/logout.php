<?php
session_start();
unset($_SESSION);
session_destroy();
?><html>
<script language='javascript'>
window.location = 'index.php';
</script>
</html>
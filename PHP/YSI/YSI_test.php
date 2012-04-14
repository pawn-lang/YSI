<?php

include('./YSI.php');

YSI_Send('first', 'hi');
YSI_Send('second', TRUE);
YSI_Send('first', 42);
YSI_Send('last', 42, TRUE);

?>

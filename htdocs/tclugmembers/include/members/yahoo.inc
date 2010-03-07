<?php
function row_place($i) { 
  $row1 = "</TR><TR>"; 
  $row2 = ""; 
  if ( ($i % 2) == 0 ) { 
    return $row1; 
  } else { 
    return $row2; 
  } 
}
?> 

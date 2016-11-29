<?php

    require("../includes/config.php");
    if($_SERVER["REQUEST_METHOD"] == "GET")
        render("find.php" , ["title" => "Get Quote"]);
    else if($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $stock = lookup($_POST["symbol"]);
        if($stock == false)
            apologize("Stock not found");
        render("ans.php" ,["symbol" => $stock["symbol"] ,"name" => $stock["name"] ,"price" => $stock["price"]] );
        
    }

?>
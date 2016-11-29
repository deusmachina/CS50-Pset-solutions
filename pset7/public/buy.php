<?php
    require("../includes/config.php");
    if($_SERVER["REQUEST_METHOD"] == "GET")
        render("buyer.php",["title" => "Buy"]);
    else if($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $price = lookup($_POST["symbol"]); 
        if(!preg_match("/^\d+$/", $_POST["shares"]))
            apologize("Invalid number of shares. ");
        else if(!$price)
            apologize("Symbol not found. ");
        else
        {
            $rows = CS50::query("SELECT cash FROM users WHERE id=?",$_SESSION["id"]);
            $ans = $_POST["shares"]*$price["price"];
            if($rows[0]["cash"] < $ans)
                apologize("Not enough cash. ");
            CS50::query("INSERT INTO portfolio (user_id, symbol, shares) VALUES(?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + ?",$_SESSION["id"],strtoupper($_POST["symbol"]),$_POST["shares"],$_POST["shares"]);
            CS50::query("INSERT INTO history (transaction, symbol, shares, price, user_id) VALUES ('BUY',?,?,?,?)", strtoupper($_POST["symbol"]), $_POST["shares"],"$".(string)$ans , $_SESSION["id"]);
            CS50::query("UPDATE users SET cash = cash - ? WHERE id = ?",$ans,$_SESSION["id"]);
            redirect("/");
        }
    }
?>
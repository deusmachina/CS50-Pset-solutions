<?php
    
    require("../includes/config.php");
    if($_SERVER["REQUEST_METHOD"] == "GET")
        render("register_form.php" ,[ "title" => "Register" ]);
        
    else if($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if(empty($_POST["username"]))
            apologize("You must provide your username.");
            
        else if(empty($_POST["password"]))
            apologize("You must provide your password.");
        
        else if(empty($_POST["confirmation"]))
            apologize("You must provide your password again.");
            
        if($_POST["password"] != $_POST["confirmation"])
            apologize("Entered passwords do not match. ");
        
        $success = CS50::query("INSERT IGNORE INTO users (username, hash, cash) VALUES(?, ?, 10000.0000)", $_POST["username"], password_hash($_POST["password"], PASSWORD_DEFAULT));
        if($success == 0)
            apologize("Entered username exists. ");
        
        $rows = CS50::query("SELECT LAST_INSERT_ID() AS id");
        $id = $rows[0]["id"];
        $_SESSION["id"]=$id;
        redirect("/");
        
    }
    
?>
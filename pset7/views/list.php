<form action="sell.php" method="post">
    <div class="form-group">
        <div class="form-group">
            <select class="form-control" name="symbol">
                <option disabled selected value="">Symbol</option>
                <?php foreach($list as $ob): ?>
                <option value='<?= $ob["symbol"] ?>'> <?= $ob["symbol"] ?> </option>
                <?php endforeach ?>
           </select>
        </div>
    </div>
    <div class="form-group">
            <button class="btn btn-default" type="submit">
                Sell
            </button>
    </div>
</form>
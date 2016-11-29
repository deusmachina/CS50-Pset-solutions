<table>
    <tr>
        <th>Transaction</th>
        <th>Date/Time</th>
        <th>Symbol</th>
        <th>Shares</th>
        <th>Price</th>
    </tr>
    <tbody>
        <?php foreach ($list as $ob): ?>
        <tr>
                <td><?= $ob["transaction"] ?></td>
                <td><?= $ob["time"] ?></td>
                <td><?= $ob["symbol"] ?></td>
                <td><?= $ob["shares"] ?></td>
                <td><?= $ob["price"] ?></td>
        </tr>
        <?php endforeach ?>
    </tbody>
</table>
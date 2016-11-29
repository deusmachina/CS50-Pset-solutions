<table>
    <tr>
        <th>Symbol</th>
        <th>Name</th>
        <th>Shares</th>
        <th>Price</th>
        <th>Total</th>
    </tr>
    <tbody>
        <?php foreach ($positions as $position): ?>
        <tr>
            <td><?= $position["symbol"] ?></td>
            <td><?= $position["name"] ?></td>
            <td><?= $position["shares"] ?></td>
            <td><?= $position["price"] ?></td>
            <td><?= $position["price"]*$position["shares"] ?></td>
        </tr>
        <?php endforeach ?>
        <tr>
            <td colspan="4">CASH</td>
            <td><?= $total ?></td>
        </tr>
    </tbody>
</table>
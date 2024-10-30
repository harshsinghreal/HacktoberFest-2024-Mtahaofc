const express = require('express');
const app = express();
const PORT = 3000;

// Middleware to parse JSON
app.use(express.json());

// In-memory array to store items
let items = [];

// GET all items
app.get('/api/items', (req, res) => {
    res.json(items);
});

// POST a new item
app.post('/api/items', (req, res) => {
    const newItem = req.body;
    items.push(newItem);
    res.status(201).json(newItem);
});

// DELETE an item by index
app.delete('/api/items/:index', (req, res) => {
    const index = req.params.index;
    if (index < 0 || index >= items.length) {
        return res.status(404).json({ message: 'Item not found' });
    }
    const deletedItem = items.splice(index, 1);
    res.json(deletedItem);
});

// Start the server
app.listen(PORT, () => {
    console.log(`Server is running on http://localhost:${PORT}`);
});

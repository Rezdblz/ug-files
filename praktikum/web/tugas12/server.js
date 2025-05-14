const express = require('express');
const db = require('./db'); // koneksi
const app = express();
const port = 3000;

app.use(express.static('public')); // Serve static files from the public folder
app.use(express.urlencoded({ extended: true })); // Parse URL-encoded form data

app.post('/submit', (req, res) => {
  const formData = req.body;

  const tl = formData.tl ? new Date(formData.tl).toISOString().split('T')[0] : null;

  const sqlInsert = `
    INSERT INTO data_user (nama, nrp, kelas, gender, agama, tempat_lahir, tanggal_lahir, alamat, sd, smp, sma, email, homepage, hobi, interest_comma)
    VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
  `;
  const values = [
    formData.nama,
    formData.nrp,
    formData.class,
    formData.gen,
    formData.agama,
    formData.tempat,
    tl,
    formData.alamat,
    formData.sd,
    formData.smp,
    formData.sma,
    formData.email,
    formData.home,
    formData.hobby,
    Array.isArray(formData.inte) ? formData.inte.join(', ') : formData.inte || 'tidak ada'
  ];

  db.query(sqlInsert, values, (err, result) => {
    if (err) {
      console.error('Error inserting data into the database:', err.message);
      res.status(500).send('Error saving data to the database.');
      return;
    }
    console.log('Data inserted successfully:', result);

    // Serve the read.html file instead of redirecting to /result
    res.sendFile(__dirname + '/public/read.html');
  });
});

//update
app.post('/update', (req, res) => {
  const formData = req.body;

  const tl = formData.tl ? new Date(formData.tl).toISOString().split('T')[0] : null;

  const sqlUpdate = `
    UPDATE data_user
    SET nama = ?, kelas = ?, gender = ?, agama = ?, tempat_lahir = ?, tanggal_lahir = ?, alamat = ?, sd = ?, smp = ?, sma = ?, email = ?, homepage = ?, hobi = ?, interest_comma = ?
    WHERE nrp = ?
  `;
  const values = [
    formData.nama,
    formData.class,
    formData.gen,
    formData.agama,
    formData.tempat,
    tl,
    formData.alamat,
    formData.sd,
    formData.smp,
    formData.sma,
    formData.email,
    formData.home,
    formData.hobby,
    Array.isArray(formData.inte) ? formData.inte.join(', ') : formData.inte || 'tidak ada',
    formData.nrp
  ];

  db.query(sqlUpdate, values, (err, result) => {
    if (err) {
      console.error('Error updating data in the database:', err.message);
      res.status(500).send('Error updating data in the database.');
      return;
    }
    console.log('Data updated successfully:', result);
    res.sendFile(__dirname + '/public/read.html'); // Redirect to read.html
  });
});
//delete
app.post('/delete', (req, res) => {
  const formData = req.body;
  const sqlDelete = 'DELETE FROM data_user WHERE nrp = ?';
  const values = [formData.nrp];

  db.query(sqlDelete, values, (err, result) => {
    if (err) {
      console.error('Error deleting data:', err);
      res.status(500).send('Error deleting data from the database.');
      return;
    }
    console.log('Data deleted successfully:', result);
    res.sendFile(__dirname + '/public/read.html'); // Redirect to read.html
  });
});

// Read
app.get('/result', (req, res) => {
  const sqlSelect = 'SELECT * FROM data_user';

  db.query(sqlSelect, (err, results) => {
    if (err) {
      console.error('Error fetching data from the database:', err.message);
      res.status(500).send('Error fetching data from the database.');
      return;
    }
    res.json(results); // Send the data as JSON
  });
});

app.get('/', (req, res) => {
  res.sendFile(__dirname + '/public/index.html');
});

app.listen(port, () => {
  console.log(`server running at http://localhost:${port}`);
});
const express = require('express');
const app = express();
const port = 3000;

let formData = {}; // simpan data form

app.use(express.static('public')); //ambil index.html dari folder public
app.use(express.urlencoded({ extended: true }));

app.post('/submit', (req, res) => {
  formData = req.body;
  res.redirect('/result');
});

app.get('/result', (req, res) => {
  const interests = Array.isArray(formData['inte'])
  ? formData['inte'].join(', ')
  : formData['inte'] || 'tidak ada';

  res.send(`
    <h1>data yang sudah di submit</h1>
    <p><strong>nama:</strong> ${formData.nama}</p>
    <p><strong>nrp:</strong> ${formData.nrp}</p>
    <p><strong>kelas:</strong> ${formData.class}</p>
    <p><strong>jenis kelamin:</strong> ${formData.gen}</p>
    <p><strong>agama:</strong> ${formData.agama}</p>
    <p><strong>tempat/tanggal lahir:</strong> ${formData.tempat} / ${formData.tl}</p>
    <p><strong>alamat:</strong> ${formData.alamat}</p>
    <p><strong>pendidikan:</strong> sd: ${formData.sd}, smp: ${formData.smp}, sma: ${formData.sma}</p>
    <p><strong>email:</strong> ${formData.email}</p>
    <p><strong>homepage:</strong> ${formData.home}</p>
    <p><strong>hobby:</strong> ${formData.hobby}</p>
    <p><strong>interest:</strong> ${interests}</p>
    <a href="/">kembali ke form</a>
  `);
});

app.listen(port, () => {
  console.log(`server running at http://localhost:${port}`);
});
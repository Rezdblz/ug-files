const mysql = require('mysql');

// Create a connection pool
const db = mysql.createPool({
  connectionLimit: 10, // Maximum number of connections
  host: '127.0.0.1',
  user: 'root',
  password: '',
  database: 'test'
});

module.exports = db;

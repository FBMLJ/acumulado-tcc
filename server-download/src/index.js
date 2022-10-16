const express = require('express')
const app = express()
const port = 3000

app.get('/', (req, res) => {
  res.send(__dirname)
})

app.get('/download', function(req, res){
    const file = `${__dirname}/../model.bin`;
    res.download(file); // Set dispositioln and send it.
  });

app.listen(port, () => {
  console.log(`Example app listening on port ${port}`)
})

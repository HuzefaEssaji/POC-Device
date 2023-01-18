const http = require("http");
const db = require("./src/models/sequelize");
require("dotenv").config();

const app = require("./src/app");

const PORT = process.env.PORT || 8000;

const server = http.createServer(app);

async function startServer() {
  server.listen(PORT, () => {
    console.log(`Listening on port ${PORT}...`);
  });
}

db.sync().then(() => {
  startServer();
});

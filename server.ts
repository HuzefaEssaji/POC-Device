import http from "http"
import app from "./src/app"
import db from "./src/sequelize";
// import TestingData from "./src/testing";

const PORT = process.env.PORT || 3000;
const server = http.createServer(app);

async function startServer() {
  server.listen(PORT, () => {
    console.log(`Listening on port ${PORT}...`);
  });
}

// db.sync({
//   force: true,
// }).then(() => {
//   TestingData()
//   startServer();
// })

db.query('SET FOREIGN_KEY_CHECKS = 0', { raw: true }).then(function () {
  db.sync().then(function () {
    // TestingData()
    startServer();
  });
});
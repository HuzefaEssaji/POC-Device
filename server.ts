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

db.sync().then(() => {
  // TestingData()
  startServer();
})
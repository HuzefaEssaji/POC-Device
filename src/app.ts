import express from "express"
import path from "path";
import morgan from "morgan";
import api from "./routes/api"
import cors from "cors"
import { graphqlHTTP } from "express-graphql"; 
import { schema } from "./schema/index"

const app = express()
app.use(cors())
app.use(express.json());
app.use(express.urlencoded({ extended: true }));
app.use(morgan("combined"));


app.use("/images", express.static(path.join(__dirname, "/uploads")));

app.use(
  "/graphql",
  graphqlHTTP({
    schema: schema,
    graphiql: true,
  })
);
app.use("/", api);

export default app;

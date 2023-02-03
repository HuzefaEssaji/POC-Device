"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
const express_1 = __importDefault(require("express"));
const path_1 = __importDefault(require("path"));
const morgan_1 = __importDefault(require("morgan"));
const api_1 = __importDefault(require("./routes/api"));
const cors_1 = __importDefault(require("cors"));
const express_graphql_1 = require("express-graphql");
const index_1 = require("./schema/index");
const app = (0, express_1.default)();
app.use((0, cors_1.default)());
app.use(express_1.default.json());
app.use(express_1.default.urlencoded({ extended: true }));
app.use((0, morgan_1.default)("combined"));
app.use("/images", express_1.default.static(path_1.default.join(__dirname, "/uploads")));
app.use("/graphql", (0, express_graphql_1.graphqlHTTP)({
    schema: index_1.schema,
    graphiql: true,
}));
app.use("/", api_1.default);
exports.default = app;

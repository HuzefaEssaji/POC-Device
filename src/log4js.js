const log4js = require("log4js");

log4js.configure({
  appenders: { log: { type: "file", filename: "console.log" } },
  categories: { default: { appenders: ["log"], level: "error" } },
});

module.exports = log4js;

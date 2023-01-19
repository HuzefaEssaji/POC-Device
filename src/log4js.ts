import log4js from "log4js"

log4js.configure({
  appenders: { log: { type: "file", filename: "console.log" } },
  categories: { default: { appenders: ["log"], level: "error" } },
});

export default log4js;

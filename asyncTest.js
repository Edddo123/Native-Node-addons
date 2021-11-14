const asyncModule = require("bindings")("asyncFib");

const asyncFibonacci = (fibRuns) => {
  return new Promise((resolve, reject) => {
    asyncModule.fibAsync(fibRuns, (err, result) => {
      if (err) reject(err);
      else resolve(result);
    });
  });
};

(async function () {
  const scopingAsyncFunction = async () => {
    const answer = await asyncFibonacci(45);
    console.log("my response", answer);
  };
  scopingAsyncFunction();
  console.log("this runs first");
})();

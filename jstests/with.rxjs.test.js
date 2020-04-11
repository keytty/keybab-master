const { Observable } = require("rxjs");
const { filter, map, scan } = require("rxjs/operators");
const { marblet, expectUpstream } = require("./marblet.lib.js");

const operators = {
  combine: (source$) => source$.pipe(scan((acc, one) => [...acc, one], [])),
};

const withJest = (actual, expected) => expect(actual).toEqual(expected);

describe("Scheduler examples", () => {
  const { combine, evenTimesTen } = operators;

  test("rxjs test simple", () => {
    marblet(
      "j-x|",
      "a-b|",
      expectUpstream({
        j: "j",
        x: "x",
      })
        .pipe(combine)
        .toBe({
          a: ["j"],
          b: ["j", "x"],
        })
    ).assess(withJest);
  });
});

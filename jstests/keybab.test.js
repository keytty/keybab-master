const keybab = require("../src/jsbridge.bs.js");

const {
  instruction,
  Action: { move },
  Command: { j },
} = keybab;

describe("instruction", () => {
  test("['j', 'x']", () => {
    expect(instruction(["j", "x"])).toEqual({
      actions: [{ type: move }],
      commands: [j],
      feedback: "x is undefined",
      nextAvailables: [j],
    });
  });
});

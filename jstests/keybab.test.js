const keybab = require("../src/forjs/jsbridge.bs.js");

const {
  instruction,
  Action: { move, horizontal, vertical },
  Command: { j },
} = keybab;

describe("instruction", () => {
  test("['j', 'x'] with reference", () => {
    expect(instruction(["j", "x"])).toEqual({
      actions: [
        {
          axis: vertical,
          amount: -1,
          type: move,
        },
      ],
      commands: [j],
      feedback: "x is undefined",
      nextAvailables: [j],
    });
  });

  test("['j', 'x'] with string", () => {
    expect(instruction(["j", "x"])).toEqual({
      actions: [
        {
          axis: "vertical",
          amount: -1,
          type: "move",
        },
      ],
      commands: ["j"],
      feedback: "x is undefined",
      nextAvailables: ["j"],
    });
  });
});

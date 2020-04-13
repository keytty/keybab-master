const keybab = require("../src/forjs/jsbridge.bs.js");

const {
  instruction,
  Action: { move },
  Keybol: { j, digits },
} = keybab;

describe("instruction", () => {
  test("['j', 'x'] with reference", () => {
    expect(instruction(["j", "x"])).toEqual({
      actions: [
        {
          coordinates: { vertical: -1, horizontal: 0 },
          type: move,
        },
      ],
      keybab: [j],
      feedback: "x is undefined",
      nextAvailables: [j, ...digits],
    });
  });

  test("['j', 'x'] with string", () => {
    expect(instruction(["j", "x"])).toEqual({
      actions: [
        {
          coordinates: { vertical: -1, horizontal: 0 },
          type: "move",
        },
      ],
      keybab: ["j"],
      feedback: "x is undefined",
      nextAvailables: ["j", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"],
    });
  });
});

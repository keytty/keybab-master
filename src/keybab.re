type instruction = {
  actions: list(Action.t),
  commands: list(Command.t),
  feedback: Feedback.t,
  nextAvailables: list(Command.t),
};

let instruction = {
  open Command;
  open Feedback;
  open Action;

  let feedbackForLastCommand = cs =>
    cs |> List.rev |> List.hd |> feedbackForCommand;

  let instructionFromCommands = cs => {
    actions: cs |> validActions,
    commands: cs |> validCommands,
    feedback: cs |> feedbackForLastCommand,
    nextAvailables: [J],
  };

  ks => ks |> List.map(keyToCommand) |> instructionFromCommands;
};

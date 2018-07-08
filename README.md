# Personal data converter

Animal Logic Python test for converting personal record files to other formats.

## Usage

Convert a JSON data file to CSV:
```python
./convert --input-file ../res/example.json --reader default --output-file ../res/output.csv --writer default
```

List all formatters:
```python
./convert --list-formatters
```

List all readers and writers for format:
```python
./convert --list-readers json --list-writers json
```

## Supports

CSV and JSON files only with following schema:

```
[
    {name: ..., address: ..., number: ...,},
    {name: ..., address: ..., number: ...,}
    {name: ..., address: ..., number: ...,}
]
```

## Extending

Implementing your own formatter, reader and writer is easy.

1. Simply create a new file and derive from following classes
2. Implement required functions
3. Register your formatter in the `FormatManager`

```python
from altest.format.format_base import ReaderBase
from altest.format.format_base import WriterBase
from altest.format.format_base import FormatBase
from altest.record import Record

class MyReader(ReaderBase):
    def read(self, filepath):
        """Must return a list of Record objects."""
        return [Record("Bemo", "Wellington", "021345678")]

class MyWriter(WriterBase):
    def write(self, records, filepath):
        """Must accept a list of records."""
        pass
   
class MyFormatter(FormatBase):
    """Make sure you register your reader and writer!"""
    def __init__(self):
        super(MyFormatter, self).__init__()
        self.register_reader("default", MyReader())
        self.register_writer("default", MyWriter())
        
class FormatManager(object):
    """A manager that hosts formatters."""
    def __init__(self):
        self.register("myformat", MyFormatter())
```

## Testing

Step in the the test directory and run the tests file like so:

```bash
cd tests
./run.py
```
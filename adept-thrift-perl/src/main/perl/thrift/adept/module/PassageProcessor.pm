################################################################################
#
# Copyright (C) 2016 Raytheon BBN Technologies Corp.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
#      http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
################################################################################
#
#
#

#
# Autogenerated by Thrift Compiler (0.9.0)
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#
require 5.6.0;
use strict;
use warnings;
use Thrift;

use thrift::adept::module::Types;
use thrift::adept::common::Types;

# HELPER FUNCTIONS AND STRUCTURES

package thrift::adept::module::PassageProcessor_process_args;
use base qw(Class::Accessor);
thrift::adept::module::PassageProcessor_process_args->mk_accessors( qw( passage ) );

sub new {
                my $classname = shift;
                my $self      = {};
                my $vals      = shift || {};
                $self->{passage} = undef;
                if (UNIVERSAL::isa($vals,'HASH')) {
                  if (defined $vals->{passage}) {
                    $self->{passage} = $vals->{passage};
                  }
                }
                return bless ($self, $classname);
}

sub getName {
                return 'PassageProcessor_process_args';
              }

sub read {
                my ($self, $input) = @_;
                my $xfer  = 0;
                my $fname;
                my $ftype = 0;
                my $fid   = 0;
                $xfer += $input->readStructBegin(\$fname);
                while (1) 
                {
                  $xfer += $input->readFieldBegin(\$fname, \$ftype, \$fid);
                  if ($ftype == TType::STOP) {
                    last;
                  }
                  SWITCH: for($fid)
                  {
                    /^1$/ && do{                    if ($ftype == TType::STRUCT) {
                      $self->{passage} = new thrift::adept::common::Passage();
                      $xfer += $self->{passage}->read($input);
                    } else {
                      $xfer += $input->skip($ftype);
                    }
                    last; };
                      $xfer += $input->skip($ftype);
                  }
                  $xfer += $input->readFieldEnd();
                }
                $xfer += $input->readStructEnd();
                return $xfer;
              }

sub write {
                my ($self, $output) = @_;
                my $xfer   = 0;
                $xfer += $output->writeStructBegin('PassageProcessor_process_args');
                if (defined $self->{passage}) {
                  $xfer += $output->writeFieldBegin('passage', TType::STRUCT, 1);
                  $xfer += $self->{passage}->write($output);
                  $xfer += $output->writeFieldEnd();
                }
                $xfer += $output->writeFieldStop();
                $xfer += $output->writeStructEnd();
                return $xfer;
              }

package thrift::adept::module::PassageProcessor_process_result;
use base qw(Class::Accessor);
thrift::adept::module::PassageProcessor_process_result->mk_accessors( qw( success ) );

sub new {
                my $classname = shift;
                my $self      = {};
                my $vals      = shift || {};
                $self->{success} = undef;
                if (UNIVERSAL::isa($vals,'HASH')) {
                  if (defined $vals->{success}) {
                    $self->{success} = $vals->{success};
                  }
                }
                return bless ($self, $classname);
}

sub getName {
                return 'PassageProcessor_process_result';
              }

sub read {
                my ($self, $input) = @_;
                my $xfer  = 0;
                my $fname;
                my $ftype = 0;
                my $fid   = 0;
                $xfer += $input->readStructBegin(\$fname);
                while (1) 
                {
                  $xfer += $input->readFieldBegin(\$fname, \$ftype, \$fid);
                  if ($ftype == TType::STOP) {
                    last;
                  }
                  SWITCH: for($fid)
                  {
                    /^0$/ && do{                    if ($ftype == TType::LIST) {
                      {
                        my $_size51 = 0;
                        $self->{success} = [];
                        my $_etype54 = 0;
                        $xfer += $input->readListBegin(\$_etype54, \$_size51);
                        for (my $_i55 = 0; $_i55 < $_size51; ++$_i55)
                        {
                          my $elem56 = undef;
                          $elem56 = new thrift::adept::common::HltContentUnion();
                          $xfer += $elem56->read($input);
                          push(@{$self->{success}},$elem56);
                        }
                        $xfer += $input->readListEnd();
                      }
                    } else {
                      $xfer += $input->skip($ftype);
                    }
                    last; };
                      $xfer += $input->skip($ftype);
                  }
                  $xfer += $input->readFieldEnd();
                }
                $xfer += $input->readStructEnd();
                return $xfer;
              }

sub write {
                my ($self, $output) = @_;
                my $xfer   = 0;
                $xfer += $output->writeStructBegin('PassageProcessor_process_result');
                if (defined $self->{success}) {
                  $xfer += $output->writeFieldBegin('success', TType::LIST, 0);
                  {
                    $xfer += $output->writeListBegin(TType::STRUCT, scalar(@{$self->{success}}));
                    {
                      foreach my $iter57 (@{$self->{success}}) 
                      {
                        $xfer += ${iter57}->write($output);
                      }
                    }
                    $xfer += $output->writeListEnd();
                  }
                  $xfer += $output->writeFieldEnd();
                }
                $xfer += $output->writeFieldStop();
                $xfer += $output->writeStructEnd();
                return $xfer;
              }

package thrift::adept::module::PassageProcessor_processAsync_args;
use base qw(Class::Accessor);
thrift::adept::module::PassageProcessor_processAsync_args->mk_accessors( qw( passage ) );

sub new {
                my $classname = shift;
                my $self      = {};
                my $vals      = shift || {};
                $self->{passage} = undef;
                if (UNIVERSAL::isa($vals,'HASH')) {
                  if (defined $vals->{passage}) {
                    $self->{passage} = $vals->{passage};
                  }
                }
                return bless ($self, $classname);
}

sub getName {
                return 'PassageProcessor_processAsync_args';
              }

sub read {
                my ($self, $input) = @_;
                my $xfer  = 0;
                my $fname;
                my $ftype = 0;
                my $fid   = 0;
                $xfer += $input->readStructBegin(\$fname);
                while (1) 
                {
                  $xfer += $input->readFieldBegin(\$fname, \$ftype, \$fid);
                  if ($ftype == TType::STOP) {
                    last;
                  }
                  SWITCH: for($fid)
                  {
                    /^1$/ && do{                    if ($ftype == TType::STRUCT) {
                      $self->{passage} = new thrift::adept::common::Passage();
                      $xfer += $self->{passage}->read($input);
                    } else {
                      $xfer += $input->skip($ftype);
                    }
                    last; };
                      $xfer += $input->skip($ftype);
                  }
                  $xfer += $input->readFieldEnd();
                }
                $xfer += $input->readStructEnd();
                return $xfer;
              }

sub write {
                my ($self, $output) = @_;
                my $xfer   = 0;
                $xfer += $output->writeStructBegin('PassageProcessor_processAsync_args');
                if (defined $self->{passage}) {
                  $xfer += $output->writeFieldBegin('passage', TType::STRUCT, 1);
                  $xfer += $self->{passage}->write($output);
                  $xfer += $output->writeFieldEnd();
                }
                $xfer += $output->writeFieldStop();
                $xfer += $output->writeStructEnd();
                return $xfer;
              }

package thrift::adept::module::PassageProcessor_processAsync_result;
use base qw(Class::Accessor);
thrift::adept::module::PassageProcessor_processAsync_result->mk_accessors( qw( success ) );

sub new {
                my $classname = shift;
                my $self      = {};
                my $vals      = shift || {};
                $self->{success} = undef;
                if (UNIVERSAL::isa($vals,'HASH')) {
                  if (defined $vals->{success}) {
                    $self->{success} = $vals->{success};
                  }
                }
                return bless ($self, $classname);
}

sub getName {
                return 'PassageProcessor_processAsync_result';
              }

sub read {
                my ($self, $input) = @_;
                my $xfer  = 0;
                my $fname;
                my $ftype = 0;
                my $fid   = 0;
                $xfer += $input->readStructBegin(\$fname);
                while (1) 
                {
                  $xfer += $input->readFieldBegin(\$fname, \$ftype, \$fid);
                  if ($ftype == TType::STOP) {
                    last;
                  }
                  SWITCH: for($fid)
                  {
                    /^0$/ && do{                    if ($ftype == TType::I64) {
                      $xfer += $input->readI64(\$self->{success});
                    } else {
                      $xfer += $input->skip($ftype);
                    }
                    last; };
                      $xfer += $input->skip($ftype);
                  }
                  $xfer += $input->readFieldEnd();
                }
                $xfer += $input->readStructEnd();
                return $xfer;
              }

sub write {
                my ($self, $output) = @_;
                my $xfer   = 0;
                $xfer += $output->writeStructBegin('PassageProcessor_processAsync_result');
                if (defined $self->{success}) {
                  $xfer += $output->writeFieldBegin('success', TType::I64, 0);
                  $xfer += $output->writeI64($self->{success});
                  $xfer += $output->writeFieldEnd();
                }
                $xfer += $output->writeFieldStop();
                $xfer += $output->writeStructEnd();
                return $xfer;
              }

package thrift::adept::module::PassageProcessor_tryGetResult_args;
use base qw(Class::Accessor);
thrift::adept::module::PassageProcessor_tryGetResult_args->mk_accessors( qw( requestId metaContents ) );

sub new {
                my $classname = shift;
                my $self      = {};
                my $vals      = shift || {};
                $self->{requestId} = undef;
                $self->{metaContents} = undef;
                if (UNIVERSAL::isa($vals,'HASH')) {
                  if (defined $vals->{requestId}) {
                    $self->{requestId} = $vals->{requestId};
                  }
                  if (defined $vals->{metaContents}) {
                    $self->{metaContents} = $vals->{metaContents};
                  }
                }
                return bless ($self, $classname);
}

sub getName {
                return 'PassageProcessor_tryGetResult_args';
              }

sub read {
                my ($self, $input) = @_;
                my $xfer  = 0;
                my $fname;
                my $ftype = 0;
                my $fid   = 0;
                $xfer += $input->readStructBegin(\$fname);
                while (1) 
                {
                  $xfer += $input->readFieldBegin(\$fname, \$ftype, \$fid);
                  if ($ftype == TType::STOP) {
                    last;
                  }
                  SWITCH: for($fid)
                  {
                    /^1$/ && do{                    if ($ftype == TType::I64) {
                      $xfer += $input->readI64(\$self->{requestId});
                    } else {
                      $xfer += $input->skip($ftype);
                    }
                    last; };
                    /^2$/ && do{                    if ($ftype == TType::LIST) {
                      {
                        my $_size58 = 0;
                        $self->{metaContents} = [];
                        my $_etype61 = 0;
                        $xfer += $input->readListBegin(\$_etype61, \$_size58);
                        for (my $_i62 = 0; $_i62 < $_size58; ++$_i62)
                        {
                          my $elem63 = undef;
                          $elem63 = new thrift::adept::common::HltContentUnion();
                          $xfer += $elem63->read($input);
                          push(@{$self->{metaContents}},$elem63);
                        }
                        $xfer += $input->readListEnd();
                      }
                    } else {
                      $xfer += $input->skip($ftype);
                    }
                    last; };
                      $xfer += $input->skip($ftype);
                  }
                  $xfer += $input->readFieldEnd();
                }
                $xfer += $input->readStructEnd();
                return $xfer;
              }

sub write {
                my ($self, $output) = @_;
                my $xfer   = 0;
                $xfer += $output->writeStructBegin('PassageProcessor_tryGetResult_args');
                if (defined $self->{requestId}) {
                  $xfer += $output->writeFieldBegin('requestId', TType::I64, 1);
                  $xfer += $output->writeI64($self->{requestId});
                  $xfer += $output->writeFieldEnd();
                }
                if (defined $self->{metaContents}) {
                  $xfer += $output->writeFieldBegin('metaContents', TType::LIST, 2);
                  {
                    $xfer += $output->writeListBegin(TType::STRUCT, scalar(@{$self->{metaContents}}));
                    {
                      foreach my $iter64 (@{$self->{metaContents}}) 
                      {
                        $xfer += ${iter64}->write($output);
                      }
                    }
                    $xfer += $output->writeListEnd();
                  }
                  $xfer += $output->writeFieldEnd();
                }
                $xfer += $output->writeFieldStop();
                $xfer += $output->writeStructEnd();
                return $xfer;
              }

package thrift::adept::module::PassageProcessor_tryGetResult_result;
use base qw(Class::Accessor);
thrift::adept::module::PassageProcessor_tryGetResult_result->mk_accessors( qw( success ) );

sub new {
                my $classname = shift;
                my $self      = {};
                my $vals      = shift || {};
                $self->{success} = undef;
                if (UNIVERSAL::isa($vals,'HASH')) {
                  if (defined $vals->{success}) {
                    $self->{success} = $vals->{success};
                  }
                }
                return bless ($self, $classname);
}

sub getName {
                return 'PassageProcessor_tryGetResult_result';
              }

sub read {
                my ($self, $input) = @_;
                my $xfer  = 0;
                my $fname;
                my $ftype = 0;
                my $fid   = 0;
                $xfer += $input->readStructBegin(\$fname);
                while (1) 
                {
                  $xfer += $input->readFieldBegin(\$fname, \$ftype, \$fid);
                  if ($ftype == TType::STOP) {
                    last;
                  }
                  SWITCH: for($fid)
                  {
                    /^0$/ && do{                    if ($ftype == TType::BOOL) {
                      $xfer += $input->readBool(\$self->{success});
                    } else {
                      $xfer += $input->skip($ftype);
                    }
                    last; };
                      $xfer += $input->skip($ftype);
                  }
                  $xfer += $input->readFieldEnd();
                }
                $xfer += $input->readStructEnd();
                return $xfer;
              }

sub write {
                my ($self, $output) = @_;
                my $xfer   = 0;
                $xfer += $output->writeStructBegin('PassageProcessor_tryGetResult_result');
                if (defined $self->{success}) {
                  $xfer += $output->writeFieldBegin('success', TType::BOOL, 0);
                  $xfer += $output->writeBool($self->{success});
                  $xfer += $output->writeFieldEnd();
                }
                $xfer += $output->writeFieldStop();
                $xfer += $output->writeStructEnd();
                return $xfer;
              }

package thrift::adept::module::PassageProcessorIf;

use strict;


sub process{
  my $self = shift;
  my $passage = shift;

  die 'implement interface';
}

sub processAsync{
  my $self = shift;
  my $passage = shift;

  die 'implement interface';
}

sub tryGetResult{
  my $self = shift;
  my $requestId = shift;
  my $metaContents = shift;

  die 'implement interface';
}

package thrift::adept::module::PassageProcessorRest;

use strict;


sub new {
                my ($classname, $impl) = @_;
                my $self     ={ impl => $impl };

                return bless($self,$classname);
}

sub process{
                my ($self, $request) = @_;

                my $passage = ($request->{'passage'}) ? $request->{'passage'} : undef;
                return $self->{impl}->process($passage);
              }

sub processAsync{
                my ($self, $request) = @_;

                my $passage = ($request->{'passage'}) ? $request->{'passage'} : undef;
                return $self->{impl}->processAsync($passage);
              }

sub tryGetResult{
                my ($self, $request) = @_;

                my $requestId = ($request->{'requestId'}) ? $request->{'requestId'} : undef;
                my $metaContents = ($request->{'metaContents'}) ? $request->{'metaContents'} : undef;
                return $self->{impl}->tryGetResult($requestId, $metaContents);
              }

package thrift::adept::module::PassageProcessorClient;


use base qw(thrift::adept::module::PassageProcessorIf);
sub new {
                my ($classname, $input, $output) = @_;
                my $self      = {};
                $self->{input}  = $input;
                $self->{output} = defined $output ? $output : $input;
                $self->{seqid}  = 0;
                return bless($self,$classname);
}

sub process{
  my $self = shift;
  my $passage = shift;

                                $self->send_process($passage);
                return $self->recv_process();
}

sub send_process{
  my $self = shift;
  my $passage = shift;

                $self->{output}->writeMessageBegin('process', TMessageType::CALL, $self->{seqid});
                my $args = new thrift::adept::module::PassageProcessor_process_args();
                $args->{passage} = $passage;
                $args->write($self->{output});
                $self->{output}->writeMessageEnd();
                $self->{output}->getTransport()->flush();
}

sub recv_process{
  my $self = shift;

                my $rseqid = 0;
                my $fname;
                my $mtype = 0;

                $self->{input}->readMessageBegin(\$fname, \$mtype, \$rseqid);
                if ($mtype == TMessageType::EXCEPTION) {
                  my $x = new TApplicationException();
                  $x->read($self->{input});
                  $self->{input}->readMessageEnd();
                  die $x;
                }
                my $result = new thrift::adept::module::PassageProcessor_process_result();
                $result->read($self->{input});
                $self->{input}->readMessageEnd();

                if (defined $result->{success} ) {
                  return $result->{success};
                }
                die "process failed: unknown result";
}
sub processAsync{
  my $self = shift;
  my $passage = shift;

                                $self->send_processAsync($passage);
                return $self->recv_processAsync();
}

sub send_processAsync{
  my $self = shift;
  my $passage = shift;

                $self->{output}->writeMessageBegin('processAsync', TMessageType::CALL, $self->{seqid});
                my $args = new thrift::adept::module::PassageProcessor_processAsync_args();
                $args->{passage} = $passage;
                $args->write($self->{output});
                $self->{output}->writeMessageEnd();
                $self->{output}->getTransport()->flush();
}

sub recv_processAsync{
  my $self = shift;

                my $rseqid = 0;
                my $fname;
                my $mtype = 0;

                $self->{input}->readMessageBegin(\$fname, \$mtype, \$rseqid);
                if ($mtype == TMessageType::EXCEPTION) {
                  my $x = new TApplicationException();
                  $x->read($self->{input});
                  $self->{input}->readMessageEnd();
                  die $x;
                }
                my $result = new thrift::adept::module::PassageProcessor_processAsync_result();
                $result->read($self->{input});
                $self->{input}->readMessageEnd();

                if (defined $result->{success} ) {
                  return $result->{success};
                }
                die "processAsync failed: unknown result";
}
sub tryGetResult{
  my $self = shift;
  my $requestId = shift;
  my $metaContents = shift;

                                $self->send_tryGetResult($requestId, $metaContents);
                return $self->recv_tryGetResult();
}

sub send_tryGetResult{
  my $self = shift;
  my $requestId = shift;
  my $metaContents = shift;

                $self->{output}->writeMessageBegin('tryGetResult', TMessageType::CALL, $self->{seqid});
                my $args = new thrift::adept::module::PassageProcessor_tryGetResult_args();
                $args->{requestId} = $requestId;
                $args->{metaContents} = $metaContents;
                $args->write($self->{output});
                $self->{output}->writeMessageEnd();
                $self->{output}->getTransport()->flush();
}

sub recv_tryGetResult{
  my $self = shift;

                my $rseqid = 0;
                my $fname;
                my $mtype = 0;

                $self->{input}->readMessageBegin(\$fname, \$mtype, \$rseqid);
                if ($mtype == TMessageType::EXCEPTION) {
                  my $x = new TApplicationException();
                  $x->read($self->{input});
                  $self->{input}->readMessageEnd();
                  die $x;
                }
                my $result = new thrift::adept::module::PassageProcessor_tryGetResult_result();
                $result->read($self->{input});
                $self->{input}->readMessageEnd();

                if (defined $result->{success} ) {
                  return $result->{success};
                }
                die "tryGetResult failed: unknown result";
}
package thrift::adept::module::PassageProcessorProcessor;

use strict;


sub new {
                  my ($classname, $handler) = @_;
                  my $self      = {};
                  $self->{handler} = $handler;
                  return bless ($self, $classname);
}

sub process {
                  my ($self, $input, $output) = @_;
                  my $rseqid = 0;
                  my $fname  = undef;
                  my $mtype  = 0;

                  $input->readMessageBegin(\$fname, \$mtype, \$rseqid);
                  my $methodname = 'process_'.$fname;
                  if (!$self->can($methodname)) {
                    $input->skip(TType::STRUCT);
                    $input->readMessageEnd();
                    my $x = new TApplicationException('Function '.$fname.' not implemented.', TApplicationException::UNKNOWN_METHOD);
                    $output->writeMessageBegin($fname, TMessageType::EXCEPTION, $rseqid);
                    $x->write($output);
                    $output->writeMessageEnd();
                    $output->getTransport()->flush();
                    return;
                  }
                  $self->$methodname($rseqid, $input, $output);
                  return 1;
}

sub process_process {
                  my ($self, $seqid, $input, $output) = @_;
                  my $args = new thrift::adept::module::PassageProcessor_process_args();
                  $args->read($input);
                  $input->readMessageEnd();
                  my $result = new thrift::adept::module::PassageProcessor_process_result();
                  $result->{success} = $self->{handler}->process($args->passage);
                  $output->writeMessageBegin('process', TMessageType::REPLY, $seqid);
                  $result->write($output);
                  $output->writeMessageEnd();
                  $output->getTransport()->flush();
}

sub process_processAsync {
                  my ($self, $seqid, $input, $output) = @_;
                  my $args = new thrift::adept::module::PassageProcessor_processAsync_args();
                  $args->read($input);
                  $input->readMessageEnd();
                  my $result = new thrift::adept::module::PassageProcessor_processAsync_result();
                  $result->{success} = $self->{handler}->processAsync($args->passage);
                  $output->writeMessageBegin('processAsync', TMessageType::REPLY, $seqid);
                  $result->write($output);
                  $output->writeMessageEnd();
                  $output->getTransport()->flush();
}

sub process_tryGetResult {
                  my ($self, $seqid, $input, $output) = @_;
                  my $args = new thrift::adept::module::PassageProcessor_tryGetResult_args();
                  $args->read($input);
                  $input->readMessageEnd();
                  my $result = new thrift::adept::module::PassageProcessor_tryGetResult_result();
                  $result->{success} = $self->{handler}->tryGetResult($args->requestId, $args->metaContents);
                  $output->writeMessageBegin('tryGetResult', TMessageType::REPLY, $seqid);
                  $result->write($output);
                  $output->writeMessageEnd();
                  $output->getTransport()->flush();
}

1;
